import random

# face down: 0
# face up: 1
CARDS_LENGTH = 20

interact_count = 0

def interact(cards, index):
    if index >= CARDS_LENGTH - 1 or cards[index] == 1:
        return 1
    
    cards[index] = 1
    
    if cards[index + 1] == 0:
        cards[index + 1] = 1
        return 0
    
    cards[index + 1] = 0
    return 0

cards = [0 for _ in range(CARDS_LENGTH)]

# while set(cards) != {1}:
#     cpu_input = random.randrange(len(cards) - 1)
#     if cards[cpu_input] == 1:
#         continue
#     print(cards)
#     interact(cards, cpu_input)
#     interact_count += 1
    
while set(cards) != {1}:
    print(cards)
    try:
        user_input = int(input("index: "))
    except ValueError:
        continue
    interact(cards, user_input)
    interact_count += 1
    
print(cards)
print(interact_count)
