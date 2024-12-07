# Supermartket-System

****Overview****
The Supermarket System is a C++ application designed to simulate the basic operations of a supermarket. The system provides two roles: Admin and Customer, each with specific functionalities.

Admins can manage product details (add, edit, delete) which are stored persistently in a text file, database.txt. Customers can purchase products, and a receipt will be geberated in the terminal.

**Features**
Admin:
  Login System: Admins must log in using their email and password.
  Product Management:
    1. Add new products to the inventory.
    2. Edit existing product details.
    3. Delete products from the inventory.
  Data Persistence: All product details are stored in database.txt for future use.
  
Customer:
  Product Purchase: Customers can browse the available products and select items to purchase.
  Receipt Generation: After completing a purchase, the system generates a detailed receipt for the customer, saved in a .txt file.
  
**System Requirements**
  
  Programming Language: C++
  
  Data Storage: A file database.txt for inventory management.

**File Structure**

main.cpp: Main program file containing the system's logic.
database.txt: File to store and retrieve product details.
receipt_<timestamp>.txt: File generated for each customer's shopping receipt.

**How to Use**
Admin:
  - Launch the program and choose Admin from the main menu.
  - Enter the admin email and password to log in.
  - Perform the following operations:
      1. Add Product: Enter details like product name, price, and quantity.
      2. Edit Product: Search for a product and modify its details.
      3. Delete Product: Remove a product from the inventory.
  - Changes are saved to database.txt.
  
Customer:
  - Launch the program and choose Customer from the main menu.
  - Browse the list of available products.
  - Select the desired products and quantities.
  - Confirm the purchase to generate a receipt.
  - A receipt with product details, quantities, prices, and total cost.

Sample output:

Main Menu:  
1. Admin  
2. Customer  
Choose an option: 1  

Enter Email: admin@gmail.com  
Enter Password: ********  

Admin Menu:  
1. Add Product  
2. Edit Product  
3. Delete Product  
4. Logout  

Enter choice: 1  
Enter product details:  
Name: Milk  
Price: 2.50  
Quantity: 20  
Product added successfully.  


Customer receipt:

Main Menu:  
1. Admin  
2. Customer  
Choose an option: 2  


Purchase successful!  
Generating receipt...  

Receipt saved as `receipt_20241125_123456.txt`.  


**Future Enhancements**
- Add support for multiple admin accounts.
- Implement discount and promotional codes for customers.
- Enable dynamic search for products in the inventory.
