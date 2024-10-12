#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

// Function to check if a binary exists
int check_binary(const char *binary) {
  return access(binary, X_OK) == 0; // Check if the binary is executable
}

int main(int argc, char *argv[]) {

  if (argc < 2) {
    printf("Usage: %s <path to a C file>\n", argv[0]);
    return 1;
  }

  // Common directories to check
  const char *dirs[] = {
      "/bin", "/usr/bin", "/usr/local/bin", "/sbin", "/usr/sbin",
      NULL // End of the array
  };

  // List of binaries to check
  const char *binaries[] = {"gcc"};
  size_t num_binaries = sizeof(binaries) / sizeof(binaries[0]);

  // Check for each binary
  for (size_t i = 0; i < num_binaries; ++i) {
    int found = 0;
    for (size_t j = 0; dirs[j] != NULL; ++j) {
      char full_path[1024];
      snprintf(full_path, sizeof(full_path), "%s/%s", dirs[j], binaries[i]);
      if (check_binary(full_path)) {
        found = 1;
        break;
      }
    }
    if (!found) {
      fprintf(stderr, "Please install: %s\n", binaries[i]);
      return -1;
    }
  }

  const char *path = argv[1];

  // Check if the path exists
  if (access(path, F_OK) != 0) {
    fprintf(stderr, "The path '%s' does not exist.\n", path);
    return 1;
  }

  // Get file info using stat
  struct stat path_stat;
  if (stat(path, &path_stat) != 0) {
    fprintf(stderr, "Failed to retrieve information for path '%s'.\n", path);
    return 1;
  }

  // Check if it's a regular file and not a directory
  if (!S_ISREG(path_stat.st_mode)) {
    fprintf(stderr, "The path '%s' is not a file.\n", path);
    return 1;
  }

  // Check if the file has a .c extension
  const char *extension = strrchr(path, '.');
  if (extension == NULL || strcmp(extension, ".c") != 0) {
    fprintf(stderr, "The path '%s' is not a valid C file\n", path);
    return 1;
  }
  const char *input_file = path;
  const char *output_binary = "output";

  pid_t pid;

  // Fork a child process
  pid = fork();

  if (pid < 0) {
    // Fork failed
    perror("Fork failed");
    return 1;
  } else if (pid == 0) {

    execlp("gcc", "gcc", input_file, "-o", output_binary, "-lcriterion", NULL);

    perror("Failed to run gcc");

    return 1;
  } else {
    // This is the parent process: Wait for the child to finish (gcc)
    int status;
    waitpid(pid, &status, 0);

    // Check if the child process (gcc) terminated successfully
    if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {

      // Fork again to run the compiled binary
      pid_t run_pid = fork();

      if (run_pid < 0) {
        perror("Fork failed while running the binary");
        return 1;
      } else if (run_pid == 0) {

        execl(output_binary, output_binary, NULL);

        // If execl() returns, there was an error
        perror("Failed to run the binary");
        return 1;
      } else {
        // Parent waits for the child process (running binary) to finish
        waitpid(run_pid, &status, 0);

        if (WIFEXITED(status)) {
          // delete the binary
          if (remove(output_binary) != 0) {
            perror("Failed to delete the binary\n");
          }
        } else {
          perror("Binary did not exit successfully\n");
        }
      }
    } else {
      perror("Compilation failed!\n");
    }
  }
  return 0;
}
