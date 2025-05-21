/*
Rock, Paper, Scissors, Lizard, Spock Game

This is the infamous game brought to popularity with the TV show The Big Bang Theory.

Users make a selection out of the options which gets compared against a computer to determine a winner.

After a winner is determined and displayed, users can continue playing by pressing Enter, and exit by pressing 'q'
*/

// Header files
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

int main() {
    // Variable to store "menu" user input or exit key to terminate loop
    char menu_input;

    // Loop to allow user to play multiple iterations depending on menu_input above
    do {
        // Vector to hold all the options of the game
        std::vector<std::string> options = {
          "Rock",
          "Paper",
          "Scissors",
          //"Lizard",
          //"Spock"
        };

        // Seed the random number generator
        // Using time(NULL) as the seed provides a value based on the current time, ensuring a different seed each time the program runs
        srand(time(NULL));

        // Variables to store choices of user and computer
        // Computer's choice is initialised to a random number up to the length of options vector
        int comp_choice = rand() % options.size();
        int user_choice = 0;

        // Variable to store result
        std::string result;

        // Dialogue / Interface
        std::cout << "================================================================\n";
        std::cout << "Welcome to Rock, Paper, Scissors, Lizard, Spock.\n";
        std::cout << "Please select your choice using numbers from the options below:\n";
        std::cout << "================================================================\n";

        // Loop through options and display each one
        for (int x = 0; x < options.size(); x++) {
            std::cout << x + 1 << ". ";
            std::cout << options[x] << "\n";
        }

        // Inform user to make a selection and store it in variable
        // Loops until user makes a valid selection
        do {
            std::cout << "Make your selection (1 - " << options.size() << "): ";
            std::cin >> user_choice;
            std::cout << "\n";

            // Check if input is valid, display message if not
            if (user_choice < 1 || user_choice > options.size()) {
                std::cout << "Invalid input.\n\n";
            }
        } while (user_choice < 1 || user_choice > options.size());

        // Minus 1 to properly reference options vector
        user_choice -= 1;

        // Nested switch statements to compare user choice's against computer's choice and save outcome
        switch (user_choice) {
            case 0: // Rock
                switch (comp_choice) {
                    case 0: // Rock
                        result = "draw";
                        break;
                    case 1: // Paper
                        result = "lose";
                        break;
                    case 2: // Scissors
                        result = "win";
                        break;
                }
                break;
            case 1: // Paper
                switch (comp_choice) {
                    case 0: // Rock
                        result = "win";
                        break;
                    case 1: // Paper
                        result = "draw";
                        break;
                    case 2: // Scissors
                        result = "lose";
                        break;
                }
                break;
            case 2: // Scissors
                switch (comp_choice) {
                    case 0: // Rock
                        result = "lose";
                        break;
                    case 1: // Paper
                        result = "win";
                        break;
                    case 2: // Scissors
                        result = "draw";
                        break;
                }
                break;
        }

        // Display outcome message
        std::cout << "-----Results-----\n";
        std::cout << "Player chose: " << user_choice + 1 << ". " << options[user_choice] << "\n";
        std::cout << "Comp chose: " << comp_choice + 1 << ". " << options[comp_choice] << "\n\n";
        std::cout << "Your " << options[user_choice] << " " << result << "s against the computer's " << options[comp_choice] << ".\n\n";

        // Get user input for game loop
        std::cout << "Press 'q' to exit. Press 'Enter' to play again. ";

        // Clear \n left in the buffer after user_choice inputs, otherwise program will think user has typed already from previous iteration
        std::cin.ignore();

        // Store user input in variable
        menu_input = std::cin.get();

        std::cout << "\n\n";
    } while (menu_input != 'q');
}