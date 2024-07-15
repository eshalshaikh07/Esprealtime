# Arduino Project with Firestore Integration

This project demonstrates a system using Arduino with Firestore for storing and managing data related to user authentication and article management.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Technologies Used](#technologies-used)
- [Setup](#setup)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
  -  [Pin Connections](#pin-connections)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This Arduino project integrates with Firestore, a NoSQL database from Firebase, to handle user authentication (login and signup) and article management (creation and viewing).

The project is divided into several components:
- **Authentication**: Users can log in using email/password or via Google OAuth.
- **Article Management**: Users can create articles and view existing articles.

## Features

- User Authentication:
  - Login with email/password
  - Login with Google OAuth
  - Signup with username/password

- Article Management:
  - Create new articles
  - View existing articles
  - Store article data in Firestore

## Technologies Used

- **Arduino IDE**: Integrated Development Environment for Arduino programming.
- **Firebase Firestore**: Cloud-based NoSQL database for storing and syncing data in real time.

## Setup

### Prerequisites

- Arduino IDE installed on your computer.
- Access to a Firebase project with Firestore enabled.
- Basic knowledge of Arduino programming and Firebase Firestore setup.

### Installation

1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/your-repository.git
   cd your-repository
   ## Pin Connections

### Components Used:

- **LEDs**: Indicators for system status.
- **Buttons**: User input for navigation and control.

### Arduino Pinout:

| Component      | Pin on Arduino | Description               |
|----------------|----------------|---------------------------|
| LED (Status)   | D13            | Status indicator LED      |
| Button (Input) | D2             | Button for user input     |
| ...            | ...            | ...                       |

Ensure to connect the components according to the pin mappings specified above to ensure proper functionality of the system.
