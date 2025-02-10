#include "../so_long.h"

void	ft_music(const char *script_path)
{

    printf("Executing the music player script...\n");
    int result = ft_system(script_path);

    if (result == 0) {
        printf("Script executed successfully.\n");
    } else {
        printf("Error: Script execution failed.\n");
    }
}
//"/home/aingunza/reproducir_musica.sh"

void	ft_stop_music(void) 
{
    printf("Stopping the music player...\n");
    
    // Use the `pkill` command to terminate VLC
    int result = ft_system("pkill -x vlc"); // -x ensures exact match for "vlc"

    if (result == 0) {
        printf("Music stopped successfully.\n");
    } else {
        printf(Err_Music);
    }
}