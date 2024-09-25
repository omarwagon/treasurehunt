
#include <iostream>

int main()
{
    srand(time(0));
    bool x_correct = false;
    bool y_correct = false;
    int map_coords;
    int tries = 5;
    int player_x_guess;
    int player_y_guess;
    int treasure_location[16] = { 0,0,0,0
                                 ,0,0,0,0
                                 ,0,0,0,0
                                 ,0,0,0,0 };

    char treasure_map[16] = { '#','#','#','#', 
                              '#','#','#','#',
                              '#','#','#','#',
                              '#','#','#','#' };
    int i = rand() % 16;
    treasure_location[i] = 1;
    
    for (int x = 0; x < 16; x++)
    {
        std::cout << treasure_location[x] << " ";
    }
    
    std::cout << "Welcome to treasure hunt!\n";
    std::cout << "Can you guess where the treasure is? You have 5 guesses!!\n";
    while (tries != 0) {
    std::cout << "4 " << treasure_location[0] << "   " << treasure_location[1] << "   " << treasure_location[2] << "   " << treasure_location[3] << std::endl;
    std::cout << "3 " << treasure_location[4] << "   " << treasure_location[5] << "   " << treasure_location[6] << "   " << treasure_location[7] << std::endl;
    std::cout << "2 " << treasure_location[8] << "   " << treasure_location[9] << "   " << treasure_location[10] << "   " << treasure_location[11] << std::endl;
    std::cout << "1 " << treasure_location[12] << "   " << treasure_location[13] << "   " << treasure_location[14] << "   " << treasure_location[15] << std::endl;
    std::cout << "  1   2   3   4\n";
        std::cout << "Enter an x coordinate between 1 and 4\n";
        std::cin >> player_x_guess;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (player_x_guess) {
        case 1:
            if (treasure_location[0] || treasure_location[4] || treasure_location[8] || treasure_location[12] == 1)
            {
                x_correct = true;
            }
            else { x_correct = false; }
        case 2:
            if (treasure_location[1] || treasure_location[5] || treasure_location[9] || treasure_location[13] == 1)
            {
                x_correct = true;
            }
            else { x_correct = true; }
        case 3:
            if (treasure_location[2] || treasure_location[6] || treasure_location[10] || treasure_location[14] == 1)
            {
                x_correct = true;
            }
            else { x_correct = false; }
        case 4:
            if (treasure_location[3] || treasure_location[7] || treasure_location[11] || treasure_location[15] == 1)
            {
                x_correct = true;
            }
            else { x_correct = false; }
        }
        std::cout << "Enter a y coordinate between 1 and 4\n";
        std::cin >> player_y_guess;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (player_y_guess) {
        case 1:
            if (treasure_location[12] || treasure_location[13] || treasure_location[14] || treasure_location[15] == 1)
            {
                y_correct = true;
            }
            else { y_correct = false; }
        case 2:
            if (treasure_location[8] || treasure_location[9] || treasure_location[10] || treasure_location[11] == 1)
            {
                y_correct = true;
            }
            else { y_correct = false; }
        case 3:
            if (treasure_location[4] || treasure_location[5] || treasure_location[6] || treasure_location[7] == 1)
            {
                y_correct = true;
            }
            else { y_correct = true; }
        case 4:
            if (treasure_location[0] || treasure_location[1] || treasure_location[2] || treasure_location[3] == 1)
            {
                y_correct = true;
            }
            else { y_correct = false; }
       
        }

        if (y_correct && x_correct == true)
        {
            std::cout << "You found the treasure!\n"; 
            break;
        }
        else 
        { 
            tries--; 
            std::cout << "You didnt find the treasure!! You have " << tries << " tries left!\n";
            //std::cout << player_x_guess * player_y_guess - 1 << std::endl;
            //treasure_map[player_x_guess * player_y_guess - 1] = 'O';
        }
    }

    return 0;

}
