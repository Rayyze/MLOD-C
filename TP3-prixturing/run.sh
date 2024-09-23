gcc -fsanitize=address -W -Wall -I./ prixTuring.c -o ../builds/prixTuring
../builds/prixTuring -i turingWinners.csv -o winners.csv -sort