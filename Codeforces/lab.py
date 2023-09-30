import pyautogui
import time

# Wait for Putty window to open and become active
time.sleep(2)

# Type message and press enter to send
pyautogui.typewrite("Hello, world!")
pyautogui.press('enter')
