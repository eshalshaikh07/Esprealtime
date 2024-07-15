#include <WiFi.h>
#include <FirebaseESP32.h>

// Replace these with your network credentials
const char* ssid = "Wi-fi name";
const char* password = "Wi-fi psw";

// Firebase project credentials
#define API_KEY "Your Firebase Web API Key" // Your Firebase Web API Key
#define DATABASE_URL "Your Firestore Databse url" // Your Firebase Database URL
#define USER_EMAIL "Your Firebase user email" // Your Firebase user email
#define USER_PASSWORD "Your Firebase user password" // Your Firebase user password

// Built-in LED pin
#define LED_PIN 2 // GPIO 2 on ESP32 (NodeMCU)

FirebaseData firebaseData;
FirebaseAuth firebaseAuth;
FirebaseConfig config;

void setup() {
  Serial.begin(115200);
  
  // Set up pin mode for the built-in LED
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW); // Ensure LED is off initially
  
  // Disconnect previous Wi-Fi connections
  WiFi.disconnect(true);
  delay(1000);
  
  // Connect to Wi-Fi
  Serial.println("Connecting to Wi-Fi");
  WiFi.begin(ssid, password);
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(500);
    Serial.print(".");
    attempts++;
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println();
    Serial.println("Connected to Wi-Fi");
  } else {
    Serial.println();
    Serial.println("Failed to connect to Wi-Fi");
    return;
  }

  // Configure Firebase
  Serial.println("Configuring Firebase");
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  firebaseAuth.user.email = USER_EMAIL;
  firebaseAuth.user.password = USER_PASSWORD;
  Firebase.begin(&config, &firebaseAuth);
  Firebase.reconnectWiFi(true);
  Serial.println("Firebase configured");

  // Delay to ensure Firebase is configured properly
  delay(2000);
}

void loop() {
  // Read from Realtime Database example
  if (Firebase.getString(firebaseData, "/ledStatus")) {
    String ledStatus = firebaseData.stringData();
    Serial.print("Realtime Database LED Status: ");
    Serial.println(ledStatus);

    // Example: Control built-in LED based on status from Realtime Database
    if (ledStatus == "true") {
      digitalWrite(LED_PIN, HIGH); // Turn the LED on
    } else {
      digitalWrite(LED_PIN, LOW); // Turn the LED off
    }

    // Update Firestore with new document containing updated data and timestamp
    updateFirestore(ledStatus);
  } else {
    Serial.println("Error reading Realtime Database LED status");
    Serial.println("REASON: " + firebaseData.errorReason());

    // Optional: Handle the error condition (e.g., retry, set default state)
    // digitalWrite(LED_PIN, LOW); // Set LED off by default or retry reading
  }

  delay(100); // Adjust delay as needed for polling frequency
}

void updateFirestore(String ledStatus) {
  // Generate timestamp
  String timestamp = String(millis()); // Using millis() as a simple example

  // Prepare data for Firestore
  String firestoreData = "{\"ledStatus\": \"" + ledStatus + "\", \"timestamp\": \"" + timestamp + "\"}";

  // Update Firestore document
  if (Firebase.setString(firebaseData, "/LED_updates/" + timestamp, firestoreData)) {
    Serial.println("Firestore document updated successfully");
  } else {
    Serial.println("Error updating Firestore document");
    Serial.println("REASON: " + firebaseData.errorReason());
  }
}
