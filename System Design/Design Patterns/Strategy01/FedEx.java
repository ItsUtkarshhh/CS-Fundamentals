public class FedEx implements ShippingStrategy {
    private double baseCost = 15.0d;
    private double perKgCost = 1.20d;

    @Override
    public void calculateShippingCost(double weight, boolean isInternational) {
        double totalCost = 0;
        if(isInternational) totalCost = baseCost + (perKgCost*weight) + 10;
        else totalCost = baseCost + (perKgCost*weight);
        System.out.printf("Your total cost for the product to be delivered is : %.2f\n", totalCost);
        return;
    }

    @Override
    public void calculateShippingTime(boolean isInternational) {
        if(isInternational) {
            System.out.println("The item will be delivered in 1-2 business days");
            return;
        }
        System.out.println("The item will be delivered in 2-3 hours");
    }
}