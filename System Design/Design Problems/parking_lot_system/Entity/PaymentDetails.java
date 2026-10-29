package parking_lot_system;

import java.sql.Date;
import java.sql.Time;
import java.time.Instant;
import java.util.Objects;

public class PaymentDetails {
    private final long transactionId;
    private final long ticketId;
    private final double transactionAmount;
    private final Instant startedAt;
    private PaymentMethod paymentMethod;
    private PaymentStatus paymentStatus;
    private Instant completedAt;

    private enum PaymentStatus {
        SUCCESS,
        PENDING,
        FAILED,
    };
    private final enum PaymentMethod {
        CREDIT_CARD,
        UPI,
        NET_BANKING
    }

    public PaymentDetails(
                            long transactionId,
                            long ticketId,
                            double amount,
                            Instant startedAt,
                            PaymentMethod paymentMethod,
                            PaymentStatus paymentStatus
                        ) 
        {
        if(amount <= 0) {
            throw new IllegalArgumentException("Amount cannot be less than 0. Enter the valid amount");
        }
        this.transactionId = Objects.requireNonNull(transactionId, "Transaction ID cannot be negative");
        this.ticketId = Objects.requireNonNull(ticketId, "Ticket ID cannot be negative");
        this.paymentMethod = Objects.requireNonNull(paymentMethod, "Payment Method cannot be NULL");
        this.transactionAmount = amount;
        this.startedAt = Instant.now();
        this.paymentStatus = PaymentStatus.PENDING;
    }

    public void markComplete() {
        this.paymentStatus = PaymentStatus.SUCCESS;
        this.completedAt = Instant.now();
    }

    public void markFailed() {
        this.paymentStatus = PaymentStatus.FAILED;
        this.completedAt = Instant.now();
    }

    public long getTransactionId() { return this.transactionId; }
    public long getTicketId() { return this.ticketId; }
    public double getAmount() { return this.transactionAmount; }
    public Instant startedAt() { return this.startedAt; }
    public PaymentMethod getPaymentMethod() { return this.paymentMethod; }
    public PaymentStatus getPaymentStatus() { return this.paymentStatus; }
}