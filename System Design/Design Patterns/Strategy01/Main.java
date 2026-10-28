import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the weight : ");
        double weight = sc.nextDouble();

        System.out.println("Is it an international delivery? : Yes/No");
        String confirmation = sc.next();
        boolean isInternational = (confirmation.equalsIgnoreCase("Yes")) ? true : false;

        ShippingStrategy strategy = new GreenDron();
        ShippingService service = new ShippingService(strategy);
        service.calculateShippingCost(weight, isInternational);
        System.out.println("---------------------------------------------------------------------------");
        service.calculateShippingTime(isInternational);

        sc.close();
    }    
}