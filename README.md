![norminette](https://github.com/LuigiEnzoFerrari/Cub3D/actions/workflows/linter.yml/badge.svg)
![build](https://github.com/LuigiEnzoFerrari/Cub3D/actions/workflows/build.yml/badge.svg)
  
# CUB 3D  
The objective of this project was to use raycasting algorithm and create a enviroment inspired by world-famous 90’s game [Wolfeninstein][Wolfeninstein] 3D using pure C language.  

# How to use

## Dependencies  

Minilibx library requires install xorg, x11 and zlib to work. So you can install this dependecies with the command bellow  
```sh
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev
```  

## File settings  

You can create or modify a file .cub with the follow keys bellow.  

| Keys | Value | Description |
|-|-|-|
| R | widht x height | Resolution |  
| NO | path/to/xpm_file | North Texture |  
| SO | path/to/xpm_file | South Texture |
| WE | path/to/xpm_file | West Texture |
| EA | path/to/xpm_file | East Texture |
| C | r, g, b | Ceilling Color|  
| F | r, g, b | Floor Color |  
|..|..|Map|  

### The Map  

The map must be a shape made with 0, 1, colosed by 1 even inside the shape, and must have one Key letter to represents the player position and direction.  

| Keys | Description |
|-|-|
| N | Player will start in north direction |
| S | Player will start in south direction |
| W | Player will start in westh direction |
| E | Player will start in east direction |   

exemple   
11111111111  
1000000**W**001  
10111000001  
101 1000001  
10111000001  
10000000001  
11111111111  


## Execute and play

Inside the repository use make command

```sh
make
```  
A binary file named cub should appers in the repository. Now execute the cub file with a map of your choose in the folder maps or make  your own map with following the [file settings](#file-settings) guide.  

```sh
./cub maps/square.cub
```

# In game  

![holder to gifs](https://raw.githubusercontent.com/LuigiEnzoFerrari/Cub3D/master/.github/images/in_game.png)  




[Wolfeninstein]: http://users.atw.hu/wolf3d/