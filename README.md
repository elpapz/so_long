# so_long
2D simple game using minilibx
This code has 1 valgrind error and it's still norminette KO! Use with precaution!
git clone <ssh>
cd so_long
make
valgrind -v --leak-check=full --track-origins=yes ./so_long_bonus <map.ber>
