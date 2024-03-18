-- Link to the problem - https://leetcode.com/problems/combine-two-tables/
-- Topic - Database
-- Runtime - Beats 100% of users with MySQL
-- My solution -----------------------------------------------------------------
# Write your MySQL query statement below
SELECT firstName, LastName, City, State 
FROM Person 
LEFT JOIN Address
ON Person.personId = Address.personId;
