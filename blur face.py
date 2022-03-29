import cv2

cap = cv2.VideoCapture(0)
faceCascade = cv2.CascadeClassifier(cv2.data.haarcascades + "haarcascade_frontalface_default.xml")

FONT = cv2.FONT_HERSHEY_PLAIN

while True:
    _, frame = cap.read()
    width = int(cap.get(3))
    height = int(cap.get(4))

    blank = frame.copy()

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    faces = faceCascade.detectMultiScale(gray, 1.09, 5, minSize=[150, 150])
    if len(faces) != 0:
        for (x, y, w, h) in faces:
            print(x, y)
            cv2.putText(frame, f"x:{x} y:{y}", (2, height - 5), FONT, 1, (0, 255, 0), 1)
            frame2 = cv2.blur(blank[y:y+h, x:x+w], (50, 50))
            blank[y:y+h, x:x+w] = frame2
    else:
        blank = cv2.blur(frame, (50, 50))

    cv2.imshow("frame1", frame)
    cv2.imshow("frame2", blank)

    if cv2.waitKey(1) == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()