# Evaluate-the-impact-of-earning-report-on-stock-price

Evaluate the impact of earning report on stock price in C++.

Project Description

• Use liburl to retrieve historical price data from Yahoo Finance: A function retrieves
the adjusted close prices for selected Russell 1000 stocks and iShares Russell 100
(IWB) into memory.
• Parse the retrieved prices and store them in STL vector for each stock and IWB.
• Create a set of classes such as class for stock to handle EPS Estimate and price
information.
• Use member functions or independent functions for all calculation. Overload a few
arithmetic operators for vector/matrix.
• The stocks and their corresponding price information for each group should be
stored in a STL map, with stock symbol as its keys.
• The AAR and CAAR for 3 groups are presented in a matrix. The row of the matrix is
the group#, matrix columns are for AAR and CAAR.
• Use Excel Driver (strongly suggested, but gnuplot could be an alternative for Apple
computers) to show the CAAR from all 3 groups in one graph.

• Program should be able to:
o Retrieve historical price data for all selected stocks and parse the retrieved
data using STL vector.
o Calculate AAR and CAAR for each group
o Populate the stock maps and AAR/CAAR matrix.
o Show an Excel graph with CAAR for all 3 groups.

• Program should have a menu of 5 options:
o Retrieve historical price data for all stocks.
o Pull information for one stock from one group.
o Show AAR or CAAR for one group.
o Show the Excel graph with CAAR for all 3 groups.
o Exit your program.

Calculation Details:
1. From Bloomberg terminal, sort all the stocks from Russell 1000 into 3 categories
according to their 2ndrd quarter 2017 earnings releases into 3 group:
a. 1st group of stocks beat EPS Estimate, such as 5% to 10% above the estimate.
b. 2nd group of stocks meet EPS Estimate, such as 5%-10% around the estimate.
c. 3rd group of stock miss EPS Estimate, such as 5% to10% below the estimate.

2. Define as day “zero” for a stock the day the earning is released.

3. Implement Bootstrapping:
a. Sampling the stocks by randomly selecting 100 stocks from each group, total
300 stocks.
b. Use libcurl lib to retrieve 241 days of historical prices for each stock and
IWB around the date of earning release (You could enhance our class
example for this purpose).
c. For each stock calculate the daily returns Rit for 120 days before the day
“zero” and 120 days after : t = -120, -119,…-1, 0, 1,…, 119, 120:
d. Calculate the corresponding daily return Rmt for IWB for the same days.
e. Define abnormal returns as the difference ARit= Rit–Rmt.
f. Calculate average daily abnormal returns for each group of stocks for all 240
reference days
g. Cumulate the returns on the first T days to CAAR
h. Repeat steps a to g 5 times and calculate the average CAAR for 3 samplings:

4. Generate an Excel chart show the averaged CAAR of all three groups, and discuss
the impact the earning releases on their stock prices. Is there any conclusion you
could draw from your project?

Project Tasks:
Task 1: Earning research: sort stocks from Russell 1000 into 3 groups based on their
earnings and EPS Estimate from Bloomberg terminal.
Task 2: Project Design:
a) Create classes and data structure such as vectors, matrix and maps.
b) Figure out how to handle historical price retrieval from Yahoo Finance for so many
stocks and parse the retrieved data?
c) Figure out how to implement your Bootstrap algorithm?
Task 3: Divide the project into modules and assign team members working on each module.
Task 5: Module Integration and Testing
Task 6: Presentation Preparation.


