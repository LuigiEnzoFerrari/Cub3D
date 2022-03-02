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
## Execute and play

Inside the repository use make command

```sh
make
```  
A binary file named cub should appers in the repository. Now execute the cub file with a map of your choose in the folder maps or make  your own map with following the [file config](#) guide.  

```sh
./cub maps/square.cub
```






[Wolfeninstein]: http://users.atw.hu/wolf3d/