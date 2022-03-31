import pyautogui
import time

# date coords
DATE_COORD = [[(270,360),(300,360),(330,360),(360,360),(390,360),(420,360),(450,360)],
              [(270,390),(300,390),(330,390),(360,390),(390,390),(420,390),(450,390)],
              [(270,420),(300,420),(330,420),(360,420),(390,420),(420,420),(450,420)],
              [(270,450),(300,450),(330,450),(360,450),(390,450),(420,450),(450,450)],
              [(270,480),(300,480),(330,480),(360,480),(390,480),(420,480),(450,480)],
              [(270,510),(300,510),(330,510),(360,510),(390,510),(420,510),(450,510)]]

# row and column start and stop
yCurrent = 0
xCurrent = 0

yStop = 0
xStop = 0

def confirm(img: str, confidence: float) -> None:
    while True:
        confirmed = pyautogui.locateOnScreen(img, confidence=confidence)
        if confirmed:
            time.sleep(.2)
            break

def default(pos: int, option: bool) -> None:
    # click on green plus
    pyautogui.moveTo(pos)
    pyautogui.click()
    time.sleep(1)
    
    # confirm that click is succesful
    confirm("confirm1.jpeg", 0.7)

    # if option is false change the option
    if option == False:
        pyautogui.moveTo(1140, 285)
        pyautogui.click()
        pyautogui.moveTo(1140, 390)
        pyautogui.click()

    # scroll down and click simpan
    pyautogui.scroll(-1000)
    time.sleep(.3)
    while True:
        simpan = pyautogui.locateOnScreen("simpan.jpeg", confidence=0.7)
        if simpan:
            time.sleep(.1)
            pyautogui.click(simpan)
            break

    # confirm simpan
    time.sleep(1)
    confirm("confirm2.jpeg", 0.7)

    # move mouse to the middle of screen
    pyautogui.moveTo(683, 384)
    pyautogui.click()
    time.sleep(.4)

time.sleep(5)

while True:
    # auto fill
    default((1290, 360), True)
    default((1290, 400), True)
    default((1290, 440), True)
    default((1290, 480), False)
    default((1290, 520), False)

# change the date
    xCurrent += 1
    if xCurrent > 6:
        xCurrent = 0
        yCurrent += 1
        
    time.sleep(.2)
    pyautogui.click(DATE_COORD[yCurrent][xCurrent])
        
    if xCurrent == xStop + 1 and yCurrent == yStop:
        break