import handy
import cv2

# getting video feed from webcam
cap = cv2.VideoCapture(1)

# capture the hand histogram by placing your hand in the box shown and
# press 'A' to confirm
# source is set to inbuilt webcam by default. Pass source=1 to use an
# external camera.
hist = handy.capture_histogram(source=1)

while True:
    ret, frame = cap.read()
    if not ret:
        break

    '''
    i = 0
    while(i < int(cap.get(3))):
        frame = cv2.line(frame, (i, 0), (i, int(cap.get(4))), (255, 0, 0), 5)
        i += 50

    j = 0
    while(j < int(cap.get(4))):
        frame = cv2.line(frame, (0, j), (int(cap.get(3)), j), (255, 0, 0), 5)
        j += 50
    '''

    # detect the hand
    hand = handy.detect_hand(frame, hist)

    # to get the outline of the hand
    # min area of the hand to be detected = 10000 by default
    custom_outline = hand.draw_outline(
        min_area=10000, color=(0, 255, 255), thickness=2)

    # to get a quick outline of the hand
    quick_outline = hand.outline

    
    # draw fingertips on the outline of the hand, with radius 5 and color red,
    # filled in.
    x = 0
    y = 0
    for fingertip in hand.fingertips:
        # Piano hard coding
        cv2.circle(quick_outline, fingertip, 5, (0, 0, 255), -1)
        x += fingertip[0]
        y += fingertip[1] 

    if len(hand.fingertips) > 0:
        x /= 5 
        y /= 5
        # x = hand.fingertips[0][0]
        # y = hand.fingertips[0][1]
        
        # black keys
        if (y <= 700):
            if (x >= 325 and x <= 475):
                print("F#")
            elif (x >= 500 and x <= 610):
                print("G#")
            elif (x >= 650 and x <= 750):
                print("A#")
        else:
            if (x <= 850 and x >= 700):
                print("B")
            elif (x <= 700 and x >= 525):
                print("A")
            elif (x <= 525 and x >= 350):
                print("G")
            elif (x <= 350 and x >= 200):
                print("F")
            elif (x <= 200 and x >= 50):
                print("E")
            elif (x >= 850 and x <= 1000):
                print("C")

    # to get the centre of mass of the hand
    com = hand.get_center_of_mass()
    if com:
        cv2.circle(quick_outline, com, 10, (255, 0, 0), -1)

    cv2.imshow("Handy", quick_outline)

    # display the unprocessed, segmented hand
    # cv2.imshow("Handy", hand.masked)

    # display the binary version of the hand
    # cv2.imshow("Handy", hand.binary)

    k = cv2.waitKey(5)

    # Press 'q' to exit
    if k == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
