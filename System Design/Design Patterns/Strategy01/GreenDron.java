import exceptions.CurrentlyUnavailableException;
import exceptions.MaxWeightReachedException;

public class GreenDron implements ShippingStrategy {
    private double maxWeight = 5.0; 
    private double baseCost = 20.0;

    @Override
    public void calculateShippingCost(double weight, boolean isInternational) {
        try {
            if(weight < maxWeight) {
                double totalCost = baseCost;
                System.out.printf("Your total cost for the product to be delivered is : %.2f\n", totalCost);
                return;
            }
        }
        catch(Exception ex) {
            if(weight > maxWeight) {
                throw new MaxWeightReachedException("Sorry, weight more than 5 Kgs are not allowed!");
            }
        }
    }

    @Override
    public void calculateShippingTime(boolean isInternational) {
        if(isInternational) {
            throw new CurrentlyUnavailableException("Sorry, International Delivery is not available currently!");
        }
        System.out.println("Your item will be delivered in 2 hours!");
    }
}