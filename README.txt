A mobile company offers the following services: 

A – Standard Subscription. The subscription cost is 50 lei. The subscription includes 100 minutes, 100 SMS, and 10GB of internet. If the 100-minute limit is exceeded, the user pays an additional 0.1 lei per minute consumed. If the SMS limit is exceeded, the customer pays an additional 0.5 lei per SMS. If the internet limit is exceeded, the user pays 1 lei for each additional GB.

B – Standard Plus Subscription. The subscription cost is 75 lei. The subscription includes 200 minutes, 200 SMS, and 15GB. If the 200-minute limit is exceeded, the user pays an additional 0.15 lei per minute consumed. If the SMS limit is exceeded, the customer pays an additional 0.75 lei per SMS. If the internet limit is exceeded, the user pays 1.5 lei for each additional GB.

Customers purchase a subscription based on their own ID, which is a 64-bit number.

From N records in management, determine the ID of the customer who pays the most for the services offered. A customer can have one or more subscriptions of the same or different types.

Input:

N - the number of records for which the analysis is performed

Client_ID Subscription_Type Total_Used_Minutes Total_Used_SMS Total_Used_GB

Output:

The ID of the customer who pays the most

Example:

Input:

3

10 A 100 100 10

20 B 200 200 15

30 A 100 150 15

Output:

30

Explanation:

The customer with ID 10 uses only what is already included in the subscription, so they only pay the subscription price of 50 lei.

The customer with ID 20 uses only what is already included in the subscription, so they only pay the subscription price of type B, which is 75 lei.

The customer with ID 30 exceeds what is included in the type A subscription, so they have to pay:

50 + (150-100)*0.5 + (15-10)*1 = 80 lei