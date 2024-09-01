# motion-detection
# ESP32-CAM Object Detection and Surveillance System

This repository contains the code and resources for an object detection and surveillance system using the ESP32-CAM development board. The system integrates real-time object detection, image capture, and motion sensing to create a versatile surveillance solution.

## Features

- **Object Detection**: Real-time object detection using a pre-trained model.
- **Motion Sensing**: A PIR motion sensor triggers image capture when motion is detected.
- **Image Capture**: Captures images when motion is detected and saves them to an SD card or sends them to a remote server.

## Hardware Requirements

- ESP32-CAM Module
- PIR Motion Sensor
- MicroSD Card
- Power Supply (e.g., 5V/2A)

## Software Requirements

- Arduino IDE or PlatformIO
- ESP32 Board Package
- CameraWebServer Library
- Pre-trained object detection model

## Wiring Diagram

![Wiring Diagram](assets/wiring_diagram.png)

## Installation

1. Clone this repository:
    ```bash
    git clone https://github.com/yourusername/esp32-cam-object-detection-surveillance.git
    cd esp32-cam-object-detection-surveillance
    ```

2. Install the required libraries:
   - ESP32-CAM-Library
   - PIR-Sensor-Library

3. Open the `src/main.cpp` file in your preferred IDE (e.g., Arduino IDE, PlatformIO).

4. Upload the code to your ESP32-CAM module.

## Usage

- Power on the ESP32-CAM module.
- When motion is detected by the PIR sensor, the system captures an image.
- The image is either stored on the SD card or sent to a remote server for further processing.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

 
