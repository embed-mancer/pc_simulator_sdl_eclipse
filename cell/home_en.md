**Dashboard System Design Document**

### Overview
This document describes the design of the car dashboard system, focusing on the key components: indicators, RPM, speed, gear position, oil level, and water temperature. Each module has its own lifecycle functions including initialization, creation, update (refresh), and day-night mode switching. This modular approach ensures separation of concerns, reusability, and ease of maintenance.

### Dashboard Architecture Diagram
Below is a simplified diagram of the different modules of the dashboard, illustrating their relationships and core functions:

```
+---------------------+    +--------------------+
|     Indicators      |    |       RPM View     |
|                     |    |                    |
|  - Init             |    |  - Init            |
|  - Create           |    |  - Create          |
|  - Refresh          |    |  - Refresh         |
|  - Toggle Day/Night |    |  - Toggle Day/Night|
+---------------------+    +--------------------+
         |                            |
         v                            v
+---------------------+    +--------------------+
|      Speed View     |    |     Gear View      |
|                     |    |                    |
|  - Init             |    |  - Init            |
|  - Create           |    |  - Create          |
|  - Refresh          |    |  - Refresh         |
|  - Toggle Day/Night |    |  - Toggle Day/Night|
+---------------------+    +--------------------+
         |                            |
         v                            v
+---------------------+    +--------------------+
|     Oil Gauge      |    |   Water Temp Gauge  |
|                    |    |                    |
|  - Init             |    |  - Init            |
|  - Create           |    |  - Create          |
|  - Refresh          |    |  - Refresh         |
|  - Toggle Day/Night |    |  - Toggle Day/Night|
+---------------------+    +--------------------+
```

### Module Descriptions

1. **Indicators Module**
   - **Purpose**: Manage various indicator lights on the dashboard, such as check engine, battery, and turn signals.
   - **Interfaces**:
     - `Init`: Initialize all required resources for the indicator system.
     - `Create`: Set up each indicator's UI elements on the screen.
     - `Refresh`: Update the state of each indicator based on sensor data.
     - `ToggleDayNightMode`: Switch between day and night UI mode.

2. **RPM View**
   - **Purpose**: Display the current revolutions per minute of the engine.
   - **Interfaces**:
     - `Init`: Initialize the RPM view resources.
     - `Create`: Create UI elements to represent RPM.
     - `Refresh`: Update the RPM value on the screen.
     - `ToggleDayNightMode`: Change colors and brightness depending on day or night mode.

3. **Speed View**
   - **Purpose**: Show the vehicle speed.
   - **Interfaces**:
     - `Init`: Initialize speed view resources.
     - `Create`: Create the UI elements for speed display.
     - `Refresh`: Update the speed on the screen.
     - `ToggleDayNightMode`: Adjust the speed display for day or night mode.

4. **Gear View**
   - **Purpose**: Display the current gear position.
   - **Interfaces**:
     - `Init`: Initialize gear view resources.
     - `Create`: Set up gear display on the UI.
     - `Refresh`: Update the gear position display based on user input.
     - `ToggleDayNightMode`: Modify the view for day or night mode.

5. **Oil Gauge View**
   - **Purpose**: Monitor and display the current oil level.
   - **Interfaces**:
     - `Init`: Initialize oil gauge resources.
     - `Create`: Set up the UI for the oil gauge.
     - `Refresh`: Update the oil level display.
     - `ToggleDayNightMode`: Adjust the gauge view for day/night mode.

6. **Water Temperature Gauge View**
   - **Purpose**: Display the current engine water temperature.
   - **Interfaces**:
     - `Init`: Initialize water temperature gauge resources.
     - `Create`: Set up the temperature gauge UI.
     - `Refresh`: Update the temperature reading.
     - `ToggleDayNightMode`: Adjust the gauge for day/night display.

```
+---------------------+        +---------------------+            +---------------------+
|   System Startup    |        |   CAN Data Received |           | Button/IO Processing|
+---------+-----------+        +---------+-----------+            +---------------------+
          |                          |                                        |
          v                          v                                        |
+---------v-------------+        +-----v---------------+                      |
| Module Initialization |      | Data Update Trigger   |                      |
| (Call each Init)      |      | (Call Refresh)        | <--------------------+
+---------+-------------+      +---------+-------------+
          |                          |
          v                          |
+---------v-----------+              |
|  Module Creation    |              |
| (Call each Create)  |              |
+---------+-----------+              |
          |                          |
          v                          |
+---------v-----------+              |
| Day-Night Mode Phase| <------------+
| (Call each module Toggle |
| meter_mode_e)       |
+---------------------+
```


### Data Flow and Interactions
- **CAN Data Processing**: The system receives real-time data from the CAN bus. Each module subscribes to the relevant data to update the UI.
- **Central Update Trigger**: Each time new data is processed, the central data model triggers the relevant module’s `Refresh` function to ensure the dashboard reflects the most up-to-date information.
- **Day-Night Mode Switching**: The `ToggleDayNightMode` interface is called when the light sensor detects a change in ambient lighting, modifying the dashboard’s colors for optimal visibility.

### Benefits of the Modular Design
- **Separation of Concerns**: Each module is responsible for one part of the UI, making it easier to maintain and extend.
- **Scalability**: Adding new features, like new gauges or indicators, is simple since they follow the same lifecycle functions.
- **Ease of Testing**: Each module can be tested independently, simplifying validation.

### Conclusion
This design ensures that the dashboard system is modular, maintainable, and easily extendable. Each module has a well-defined responsibility with interfaces that support initialization, UI creation, real-time refreshing, and day-night adjustments.

Please let me know if you need more details on any of the modules or further explanations for leadership presentation.
