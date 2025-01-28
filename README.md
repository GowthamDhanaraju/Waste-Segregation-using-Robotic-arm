# Smart Waste Segregation System Using YOLOv8 and Arduino

This project implements a smart waste segregation system combining computer vision and robotic control to identify, classify, and sort recyclable and non-recyclable waste. The system uses YOLOv8 for object detection and Arduino for robotic arm control.
Features

    Object Detection: Utilizes YOLOv8 to detect and classify objects like books, bottles, scissors, toothbrushes, and more.
    Real-time Segregation: Identifies objects from a live camera feed and categorizes them as recyclable or non-recyclable waste.
    Robotic Arm Integration: Commands a robotic arm with servos to pick and place objects in the appropriate bin.
    Serial Communication: Uses serial communication to send commands from the Python program to the Arduino.

Workflow

    YOLOv8 Object Detection:
        Captures live video from the webcam.
        Detects objects and classifies them using pre-trained YOLOv8 weights.
        Filters objects based on a predefined list of recyclable and non-recyclable items.

    Command Transmission:
        Sends segregation commands (recycle, non-recycle, or reset) to the Arduino via serial communication.

    Robotic Arm Operation:
        Executes corresponding actions to pick up the detected item and place it in the respective bin.

Hardware Requirements

    Camera: For real-time object detection.
    Arduino Board: To control the robotic arm.
    Labeled Bins: For recyclable and non-recyclable waste.
    Servos: For robotic arm movements.
    Power Supply: To power the servos and Arduino.

Software Requirements

    Python Packages:
        Ultralytics: For YOLOv8 implementation.
        OpenCV: For image processing.
        Serial: For communication with Arduino.
    Arduino IDE: For uploading servo control code to the Arduino.

System Design
Python Script

    Loads the YOLOv8 model and captures frames from the webcam.
    Filters objects by class, draws bounding boxes, and labels them.
    Sends commands to the Arduino for segregation based on object class.

Arduino Script

    Listens for commands (recycle, non-recycle, or reset) over serial.
    Controls servos for the robotic arm to pick and place items in the appropriate bin.

Object Classes
Recyclable (Command: recycle)	Non-Recyclable (Command: non-recycle)
Book (69)	Toothbrush (79)
Bottle (39)	Mouse (62)
Scissors (74)	Banana (45)
Tie (26)	Teddy Bear (76)
