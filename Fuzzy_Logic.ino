// Fuzzy Logic Membership Functions
double poor(double x) {
    return max(0.0, 1.0 - x / 30.0);
}

double good(double x) {
    return max(0.0, min(x / 50.0, 1.0));
}

double excellent(double x) {
    return max(0.0, (x - 50.0) / 30.0);
}

// Fuzzy Logic Rule Evaluation
double applyRule(double inputTemp, double inputHumidity) {
    double rule1 = min(poor(inputTemp), poor(inputHumidity));
    double rule2 = min(excellent(inputTemp), good(inputHumidity));
    double rule3 = min(good(inputTemp), excellent(inputHumidity));

    // Defuzzification (Centroid Method)
    double numerator = rule1 * 10.0 + rule2 * 30.0 + rule3 * 70.0;
    double denominator = rule1 + rule2 + rule3;

    if (denominator != 0.0) {
        return numerator / denominator;
    }

    return 0.0; // Default value
}

void setup() {
    Serial.begin(9600);
}

void loop() {
    double temperature, humidity;

    Serial.print("Enter temperature (in Celsius): ");
    while (!Serial.available()) {
        // Wait for user input
    }
    temperature = Serial.parseFloat();
    Serial.println(temperature);

    Serial.print("Enter humidity (0-100%): ");
    while (!Serial.available()) {
        // Wait for user input
    }
    humidity = Serial.parseFloat();
    Serial.println(humidity);

    // Fuzzy Logic Inference and Control
    double airConditioningPower = applyRule(temperature, humidity);

    Serial.print("Air Conditioning Power: ");
    Serial.println(airConditioningPower);
}
