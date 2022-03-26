# COMP2113-Group-project

Group members: Tang Zixuan (3035449645); Wang Bingzhang ()

## Game description：

This game is based on the Coronavirus outbreak in the world today. In this game, players will play the role of the leader of the World Health Organization (WHO). Players 
need to make the best choice according to their own ideas to reduce the infection rate and death rate of Coronavirus, and finally save the world. The basic rule of the 
game is each turn player have to choose to take a measure to combat COVID-19, which changes your supporting rate, your budget, and the rate of infection and death of the 
virus. There are also emergencies that may occur each turn, and the player has to make a series of choices to deal with them. If the infection rate or fatality rate of 
the virus drops to zero at the end of the game, the player wins the game, if the player's supporting rate or budget is zero at the end of the game, the player loses the 
game. Tip: If the player still doesn't win the game after 10 turns, the public will lose patience and the player will still be judged to lose the game. So, optimize your 
options and win the war against viruses.

## Features to be implemented
1. Generation of random game sets or events:
   - Whether an emergency will be triggered on a specific day is random
   - The type of emergency can be random
2. Data structures for storing game status：
   - Strings for basic texts
   - Arrays to store pre-specified emergency events and possible actions
   - A linked list to store a sequence of daily status
3. Dynamic memory management:
   - applied when building the linked list
4. File input/output:
   - input some other header files
   - create a ranking list based on the number of turns, budget spent and output to another file
5. Program codes in multiple file
   - Tentative list of files: (1) Covidgame (main game file) (2) getgamerank.cpp (print the leaderboard) (3) getgamerank.h 
