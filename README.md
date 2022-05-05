# COMP2113-Group-project

Group members: Tang Zixuan (3035449645); Wang Bingzhang (3035835272)

## Game description：

This game is based on the Coronavirus outbreak in the world today. In this game, players will play the role of the leader of the World Health Organization (WHO). Players 
need to make the best choice according to their own ideas to reduce the infection rate and death rate of Coronavirus, and finally save the world.

Starting status: 
Initial funding = 100billion; 
Initial support rate = 100%; 
Initial Infection rates = 50%;
Initial death rates = 1%.

Basic rules:  
In each turn, the player have to choose to take a measure to combat COVID-19, which changes your supporting rate, your budget, and the rate of infection and death rate of the 
virus. There are also 'breaking news' that may be triggered each turn, and how the player make choices accordingly will further affect the aforementioned four statistics, either in a favorable or disadvantageous manner. 

The player wins the game if (1) the infection rate drops to zero, or (2) the death rate drops to zero. The player loses the 
game if (1) the supporting rate becomes zero, or (2) the budget becomes zero, or (3) the number of turns reaches 100. In addition, choosing the inethical measure 'Spread fake news to exaggerate your contributions' may also lead to a failure in the future (This is unknown to the palyer). 

So, optimize your 
choices and win the war against viruses!

## Features to be implemented
1. Print the up-to-date status
   - Requirement 2: Struct is used to store the daily status
2. Print the main menu and read the player's choice
   - Requirement 2: Strings are used for basic texts
3. Display the background information if the player choose to view it
   - Requirement 4: background information as file input
4. Print the action menu (7 measures included) and read the player's choice
   - Requirement 2: Strings are used for basic texts
5. Trigger a random 'breaking news' with probability 5/7
   - Requirement 1: Generation of random game sets or events
6. Update and store the daily status
   - Requirement 2: Struct is used to store the daily status in each turn
   - Requirement 3: A linked list is built to store daily status sequentially
7. Save all the daily records till the end of the game
   - Requirement 3: A linked list is used to store all records
   - Requirement 4: Daily records are written and output to an external file
   - Requirement 5:Program codes in multiple file
                   Tentative list of files: (1) Covidgame (main game file) (2) getgamerank.cpp (print the leaderboard) (3) getgamerank.h 

## non-standard C/C++ libraries
Not used.

## Compilation and execution instructions
In each turn,
1. The main menu is displayed. Please enter 1,2,3, or 0, for different actions
   - If you want to take the measure, enter 1
   - If you want to view your current status, enter 2
   - If you want to know how each measure changes your daily status, enter 3 (Note that this only contains basic information)
   - If you want to exit, enter 0
2. If '1' is entered, the screen will show (1) the random event of that day, and (2) the 7 measures that you can take. Please enter 1-7 for the measure you plan to take. (Note that the random event may further change your daily status, so the ultimate changes can be different from those provided in the basic infomation)

Repeat the steps mentioned above until you either win or lose the game. 
