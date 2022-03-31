import random

choice = [i for i in range(1, 101)]

for _ in range(len(choice)):
    pick = random.choice(choice)
    input(pick)
    choice.remove(pick)
