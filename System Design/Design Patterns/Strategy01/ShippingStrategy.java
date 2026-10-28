public interface ShippingStrategy {
    void calculateShippingCost(double weight, boolean isInternational);
    void calculateShippingTime(boolean isInternational);
}