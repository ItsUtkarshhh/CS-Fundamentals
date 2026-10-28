import exceptions.CurrentlyUnavailableException;

public class USPS implements ShippingStrategy {
    private double baseCost = 5.00;
    private double perKgCost = 0.50;

    @Override
    public void calculateShippingCost(double weight, boolean isInternational) {
        double totalCost = baseCost + (perKgCost*weight);
        System.out.printf("Your total cost for the product to be delivered is : %.2f\n", totalCost);
        return;
    }
    
    @Override
    public void calculateShippingTime(boolean isInternational) {
        try {
            if(isInternational == false) System.out.println("The item will be delivered in 5-7 business days");
        }
        catch(CurrentlyUnavailableException ex) {
            if(isInternational) {
                throw new CurrentlyUnavailableException("Sorry, Internation Delivery Is Not Available Currently!");
            }
        }
        catch(Exception ex) {
            throw new Exception("Unknown Exception has occured");
        }
    }
}