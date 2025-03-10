How to Use the Music Player

    Save the Bash script (play_music.sh) with the logic to play your music file using VLC.
Make the script executable:   
      
    chmod +x play_music.sh
    
Replace the script path in the C program with the full path to your play_music.sh.
Compile the C program:
      
    gcc -o music_player music_player.c

Run the compiled program to start playing music:
      
    ./music_player

Lista de assets hechos por mi:
textures del suelo
texxtures de las paredes 

Here’s a brief explanation of each function in your provided code for the "so_long" game, written in C using the MLX42 library. The game appears to be a 2D grid-based game where a player collects coins and reaches an exit.

---

### **Counting and Collecting Functions**
1. **`collect_count(t_game *game)`**  
   Counts the total number of collectibles ('C') in the 2D map by iterating through each cell.

2. **`coin_collecter(t_game *game)`**  
   Handles coin collection when the player moves onto a 'C' tile, updates the count, and checks if the player wins or loses when reaching the exit ('E').

---

### **Memory Management Functions**
3. **`free_img(t_game *game)`**  
   Frees all MLX image resources (wall, floor, player, exit, coin) and the image struct.

4. **`free_textures(t_game *game)`**  
   Frees all MLX texture resources (wall, floor, player, exit, coin) and the texture struct.

5. **`free_map(t_game *game)`**  
   Frees the 2D map array and the map struct.

6. **`free_player(t_game *game)`**  
   Frees the player struct.

7. **`ft_end_game(t_game *game)`**  
   Cleans up all game resources (images, textures, MLX instance, map, player, window) and exits the program.

---

### **Map Duplication and Validation (Flood Fill)**
8. **`duplicate_map(t_game *game)`**  
   Creates a duplicate of the 2D map for validation purposes.

9. **`free_duplicate_map(char **map, int rows)`**  
   Frees the memory allocated for a duplicated map.

10. **`ft_flood_doer(t_game *game, int y, int x, char **map)`**  
    Recursively performs a flood-fill algorithm from the player's position to mark reachable areas with 'X'.

11. **`element_counter(t_game *game, char **map_copy, int *collecs, int *exits)`**  
    Counts reachable collectibles ('C') and exits ('E') in the flood-filled map copy.

12. **`ft_file_validator_map(t_game *game)`**  
    Validates the map by ensuring all collectibles and exactly one exit are reachable using flood-fill.

---

### **Game Initialization and Main Loop**
13. **`mlx_loop_wrapper(void *param)`**  
    A placeholder function for the MLX loop hook (currently does nothing).

14. **`init_game(t_game *game)`**  
    Initializes the game: sets up MLX, loads images, draws the map, and hooks key events.

15. **`null_settlers(t_game *game)`**  
    Initializes all game struct pointers to NULL.

16. **`dealbreakers(t_game *game)`**  
    Checks map validity (walls and reachability) and starts the game if valid.

17. **`main(int argc, char **argv)`**  
    Entry point: validates arguments, allocates game structs, reads the map, and starts the game.

---

### **Map Element Validation**
18. **`ft_check_counts(int E, int P, int C)`**  
    Ensures the map has exactly one exit ('E'), one player ('P'), and at least one collectible ('C').

19. **`find_initial_position(t_game *game)`**  
    Locates the player's starting position ('P') on the map and ensures there’s exactly one.

---

### **Map Validation Helpers**
20. **`ft_map_empty(char **map)`**  
    Checks if the map is NULL (empty).

21. **`ft_validate_walls(t_game *game)`**  
    Ensures the map is surrounded by walls ('1') on all sides.

22. **`validate_map(char **map, t_game *game)`**  
    Combines map emptiness and wall validation checks.

---

### **Player Movement**
23. **`ft_up(t_game *game)`**  
    Moves the player up if not blocked by a wall, updates the map, and handles collectibles.

24. **`ft_down(t_game *game)`**  
    Moves the player down if not blocked by a wall, updates the map, and handles collectibles.

25. **`ft_left(t_game *game)`**  
    Moves the player left if not blocked by a wall, updates the map, and handles collectibles.

26. **`ft_right(t_game *game)`**  
    Moves the player right if not blocked by a wall, updates the map, and handles collectibles.

27. **`ft_my_hook(mlx_key_data_t keydata, void *param)`**  
    Handles key inputs (WASD or arrows for movement, ESC to exit).

---

### **Graphics and Rendering**
28. **`ft_boot_img(t_game *game)`**  
    Loads PNG textures (wall, floor, player, exit, coin) into the game struct.

29. **`img_to_textures(t_game *game)`**  
    Converts loaded textures into MLX images and frees the textures.

30. **`draw_floor(t_game *game)`**  
    Draws the floor tiles across the entire map.

31. **`draw_map(t_game *game)`**  
    Renders the map by placing images (walls, coins, exit, player) over the floor.

---

### **Map Reading and Sizing**
32. **`map_size(t_game *game, char **map)`**  
    Calculates the map’s dimensions (rows, columns) and window size.

33. **`ft_validate_file(char *map_path)`**  
    Ensures the map file has a ".ber" extension.

34. **`ft_read_map(char *map_path)`**  
    Reads the map file into a 2D array, splitting by newlines.

---

### **Wall Validation Helpers**
35. **`is_row_surrounded_by_walls(char *row)`**  
    Checks if a row starts and ends with a wall ('1').

36. **`are_row_lengths_consistent(char **map, int rows)`**  
    Verifies that all map rows have the same length.

37. **`map_corners(char **map, int rows)`**  
    Ensures the map’s four corners are walls ('1').

38. **`is_row_all_walls(char *row)`**  
    Checks if a row consists entirely of walls ('1').

39. **`wall_checker(t_game *game)`**  
    Validates that the map is fully enclosed by walls (top, bottom, sides).

---

### **Summary**
These functions collectively implement a simple 2D game where a player navigates a map, collects coins, and reaches an exit. The code handles map validation (walls, reachability), player movement, graphics rendering with MLX42, and memory management. It’s designed to be robust with error checking and cleanup.
Bonus:

Animación del personaje no bonus: Amoung us
Todo respecto al personaje 1 y 2 del bonus:

Status de cada personaje:

| Personaje  | Modelo | Shader | Animation |
| ------------- | ------------- |  ------------- |  ------------- |
| Waterboy  | Si  | Si |  No  |
| Lavagirl  | No  | Si  | No  |
| Amoung_us | Si  | Si  | Si  |


| Objeto  | Modelo | Shader |
| ------------- | ------------- |  ------------- |
| Suelo | Hecho | Hecho |
| Pared | NO Hecho | NO Hecho |
| l4v4 | Medio Hecho | Medio Hecho |
| 4qu4 | Hecho | Hecho |
