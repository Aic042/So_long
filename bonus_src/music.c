#include <stdlib.h>
#include <stdio.h>

int main() {
    const char	*script_path = "/home/aingunza/reproducir_musica.sh"; // Path to your Bash script

    printf("Executing the music player script...\n");
    int result = system(script_path);

    if (result == 0) {
        printf("Script executed successfully.\n");
    } else {
        printf("Error: Script execution failed.\n");
    }

    return 0;
}
