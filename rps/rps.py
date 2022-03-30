import random

RPS = ['r', 'p', 's']
score = 0

while True:
    player_input = None
    
    while player_input not in RPS:
        player_input = str(input("r/p/s: "))[0]
        
    computer_input = random.choice(RPS)

    print(f"{player_input} vs {computer_input}")

    match player_input:
        case 'r':
            match computer_input:
                case 'p':
                    result = "lose"
                    score -= 1
                    
                case 's':
                    result = "win"
                    score += 1
                    
                case _:
                    result = "draw"
        
        case 'p':
            match computer_input:
                case 'r':
                    result = "win"
                    score += 1
                    
                case 's':
                    result = "lose"
                    score -= 1
                    
                case _:
                    result = "draw"
                    
        case 's':
            match computer_input:
                case 'r':
                    result = "lose"
                    score -= 1
                
                case 'p':
                    result = "win"
                    score += 1
                    
                case _:
                    result = "draw"
                    
    print(result)
    print(f"score: {score}")
