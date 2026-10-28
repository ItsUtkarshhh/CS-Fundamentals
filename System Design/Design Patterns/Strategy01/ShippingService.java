public class ShippingService {
    private ShippingStrategy strategy;

    public ShippingService(ShippingStrategy strategy) {
        this.strategy = strategy;
    }

    void calculateShippingCost(double weight, boolean isInternational) {
        strategy.calculateShippingCost(weight, isInternational);
    }

    void calculateShippingTime(boolean isInternational) {
        strategy.calculateShippingTime(isInternational);
    }
}