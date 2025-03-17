from abc import ABC, abstractmethod

class PaymentStrategy(ABC):
    @abstractmethod
    def pay(self, amount):
        pass

class CreditCardPayment(PaymentStrategy):
    def __init__(self, name, card_number):
        self.name = name
        self.card_number = card_number
    def pay(self, amount):
        print(f"{self.name} paid ${amount} using card number {self.card_number}")

class PayPalPayment(PaymentStrategy):
    def __init__(self, email):
        self.email = email
    def pay(self, amount):
        print(f"${self.email} paid ${amount} using PayPal")

class BitCoinPayment(PaymentStrategy):
    def __init__(self, bitcoin_address):
        self.bitcoin_address = bitcoin_address
    def pay(self, amount):
        print(f"${self.bitcoin_address} paid ${amount} using BitCoin")

class PaymentProcessor:
    def __init__(self, strategy: PaymentStrategy):
        self._payment_strategy = strategy

    def set_strategy(self, strategy: PaymentStrategy):
        self._payment_strategy = strategy
    
    def process_payment(self, amount):
        self._payment_strategy.pay(amount)
if __name__ == "__main__":
    credit_card = CreditCardPayment("Bonike", "1234 5678 9101 1121")
    paypal = PayPalPayment("bonik@gmail.com")
    bitcoin = BitCoinPayment("1A1zPhjh33xZ")

    processor = PaymentProcessor(credit_card)
    processor.process_payment(100)
    processor.set_strategy(paypal)
    processor.process_payment(200)
    processor.set_strategy(bitcoin)
    processor.process_payment(300)
