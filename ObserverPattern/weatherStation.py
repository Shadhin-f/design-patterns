from abc import ABC, abstractmethod

class Observer(ABC):
    @abstractmethod
    def update(self, temperature: float, humidity: float, pressure: float):
        pass

# Creating the subject
class WeatherStation:
    def __init__(self):
        self._observers = []
        self._temperature = 0.0
        self._humidity = 0.0
        self._pressure = 0.0
    
    def register_observer(self, observer: Observer):
        """Adds an observer to the list"""
        self._observers.append(observer)
    def remove_observer(self, observer: Observer):
        """Removes an observer from the list"""
        self._observers.remove(observer)

    def notify_observers(self):
        """Notifies all observers about the latest weather update"""
        for observer in self._observers:
            observer.update(self._temperature, self._humidity, self._pressure)
    
    def set_weather_data(self, temperature: float, humidity: float, pressure: float):
        """Update and Notify"""
        self._temperature = temperature
        self._humidity = humidity
        self._pressure = pressure
        self.notify_observers()

# Concrete Observers

class CurrentConditionsDisplay(Observer):
    def update(self, temperature: float, humidity: float, pressure: float):
        print(f"Current Conditions: {temperature}C, {humidity}%, {pressure}Pa")
    
class ForecastDisplay(Observer):
    def update(self, temperature: float, humidity: float, pressure: float):
        if temperature > 30:
            print("Forecast: Hot day ahead")
        else:
            print("Forecast: Normal day ahead")

if __name__ == "__main__":
    weather_station = WeatherStation() # Subject

    #Create Observers
    current_condition = CurrentConditionsDisplay()
    forecast = ForecastDisplay()

    #register observers
    weather_station.register_observer(current_condition)
    weather_station.register_observer(forecast)
    print("\nFirst weather update")
    weather_station.set_weather_data(25, 60, 1013)
    print("\nSecond weather update")
    weather_station.set_weather_data(35, 70, 1013)
    weather_station.remove_observer(forecast)
    print("\nThird weather update")
    weather_station.set_weather_data(15, 80, 1013)
