## Systems Final Project: UNO

### Project Members

Celine Yan and Jiawei Chen (Both in Period 5)



### How to compile

1. In terminal, run `make`
2. Run `make run` 
3. Enjoy!


### Things to keep in mind

- Like the typical UNO, players can either place down cards, draw a card, or pass the turn.
- Our game is *case sensitive* when putting down cards or calling a command.
  - Cards must be in **UPPERCASE**
  - Commands must be in **lowercase**
- If a user passes without drawing, they will be prompted to draw first.
- `<color> +2`, `WILD +4` and `WILD COLOR` cards work, 'SKIP' and 'REVERSE' were extremely hard to implement, so they don't change the course of the game at this stage.

### Cool Features!
- Because we couldn't implement a fully working networking system in the end, we simulated that player experience by throwing in a `system("clear");` call in the beginning of each player's turn
- +2 and +4 work beautifully
- Putting a WILD COLOR or WILD +4 card will prompt user to provide a new color for the current card. 
- Call `help` anytime, spam it even, but still be able to play the game!
- We can distinguish whether you made a typo to your card or the card you selected from your hand was invalid in accordance to the current card in the pile, with two different print statements. 


### List of all the files in the repo

- README.md
- DESIGN.txt
- DEVLOG.txt
- makefile
- main.c
- deck.h
  - deck.c
- commands.h
  - commands.c
- helperFxns.h
  - helperFxns.c
