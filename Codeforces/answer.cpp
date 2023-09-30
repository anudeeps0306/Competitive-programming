// #include <bits/stdc++.h>

// using namespace std;
// #define int long long
// int32_t main()
// {
//     int t;
//     cin >> t;

//     while (t--){
//         int n;
//         cin>>n;
//         if(n==1){
//             cout<<0<<endl;
//         }
//         else{
//             int ans = sqrt(n-1);
//             cout<<ans<<"\n";
//         }
//     }
        
//     return 0;
// }


// CREATE (e1:Person {name: 'DAN'}),
// (e2:Person {name: 'ANN'}),
// (e3:Person {name: 'SALLY'}),
// (e4:Person {name: 'MELISSA'}),
// (e5:Person {name: 'JENIFFER'}),
// (e6:Person {name: 'DIANA'}),
// (e7:Person {name: 'JOE'}),
// (e8:Person {name: 'JOHN'}),
// (e9:Person {name: 'MARK'})
// CREATE(c1:Company {name: 'XYZ'}),
// (c2:Company {name: 'NeO4j'}),
// (c3:Company {name: 'ABC'}),
// (c4:Company {name: 'Company1'}),
// (c5:Company {name: 'Company2'})
// CREATE(l1:Language {name: 'INTEGRATION'}),
// (l2:Language {name: 'APPLICATION'}),
// (l3:Language {name: 'DATA_ETL'}),
// (l4:Language {name: 'QUERY_LANGUAGE'}),
// (l5:Language {name: 'GRAPHS'}),
// (l6:Language {name: 'JAVA'}),

// (e8)-[:WORKS_FOR]->(c1),
// (e8)-[:LIKES]->(l6),
// (e8)-[:LIKES]->(l2),
// (e8)-[:IS_FRIEND_WITH]->(e3),

// (e1)-[:LIKES]->(l1),
// (e1)-[:LIKES]->(l3),
// (e1)-[:WORKS_FOR]->(c3),

// (e2)-[:LIKES]->(l2),
// (e2)-[:WORKS_FOR]->(c3),
// (e2)-[:IS_FRIEND_WITH]->(e1),

// (e3)-[:LIKES]->(l1),
// (e3)-[:WORKS_FOR]->(c1),

// (e4)-[:LIKES]->(l3),
// (e4)-[:LIKES]->(l4),
// (e4)-[:LIKES]->(l5),
// (e4)-[:WORKS_FOR]->(c5),

// (e5)-[:LIKES]->(l5),
// (e5)-[:LIKES]->(l6),
// (e5)-[:IS_FRIEND_WITH]->(e9),
// (e5)-[:IS_FRIEND_WITH]->(e4),
// (e5)-[:IS_FRIEND_WITH]->(e2),
// (e5)-[:IS_FRIEND_WITH]->(e3),
// (e5)-[:IS_FRIEND_WITH]->(e8),
// (e5)-[:WORKS_FOR]->(c2),

// (e6)-[:LIKES]->(l5),
// (e6)-[:LIKES]->(l4),
// (e6)-[:WORKS_FOR]->(c4),

// (e7)-[:LIKES]->(l4),
// (e7)-[:IS_FRIEND_WITH]->(e9),
// (e7)-[:IS_FRIEND_WITH]->(e6),

// (e9)-[:LIKES]->(l5)

// return *

CREATE (:Person {name:'Ron Howard',age: 35,address:"123 Main st"}),
(:Person{name:'Robert Zerneckis',age: 34,address:"125 Main st"}),
(:Person{name:'Penny Marshall',age: 36,address:"122 Main st"}),
(:Person{name:'Tom Hanks',age: 40,address:"15 Main st"}),
(:Person{name:'John Patrick Stanley',age: 70,address:"1565 Main st"}),
(:Person{name:'Nora Ephron',age: 50,address:"1252 Main st"}),
(:Person{name:'Tom Tykwer',age: 56,address:"1252 Ma2in st"}),
(:Person{name:'Lilly Wacholoy',age: 89,address:"1225 Main st"}),
(:Person{name:'Lona Wacholonche',age: 90,address:"1252 Main st"});

CREATE (:Movie {name:'The Polar Express',profit :3000}),
(:Movie {name:'A League of Thier Own',profit :6000}),
(:Movie {name:'Cast Away',profit :33000}),
(:Movie {name:'Apollo 13',profit :300033}),
(:Movie {name:'That Things You Do',profit :35000}),
(:Movie {name:'Cloud Atlas',profit :345000}),
(:Movie {name:"You've Got the Mail",profit :30050}),
(:Movie {name:'Joe Verus The Valacano',profit :3000}),
(:Movie {name:'That Things You Do',profit :33000});

MATCH (p:Person {name: 'Robert Zerneckis'}), (m:Movie {name: 'The Polar Express'})
CREATE (p)-[:Directed]->(m);
MATCH (p:Person {name: 'Robert Zerneckis'}), (m:Movie {name: 'Cast Away'})
CREATE (p)-[:Directed]->(m);
MATCH (p:Person {name: 'Ron Howard'}), (m:Movie {name: 'Apollo 13'})
CREATE (p)-[:Directed]->(m);
MATCH (p:Person {name: 'Penny Marshall'}), (m:Movie {name: 'A League of Thier Own'})
CREATE (p)-[:Directed]->(m);
MATCH (p:Person {name: 'Tom Hanks'}), (m:Movie {name: 'That Things You Do'})
CREATE (p)-[:Directed]->(m);
MATCH (p:Person {name: 'John Patrick Stanley'}), (m:Movie {name: 'Joe Verus The Valacano'})
CREATE (p)-[:Directed]->(m);
MATCH (p:Person {name: 'Nora Ephron'}), (m:Movie {name: "You've Got the Mail"})
CREATE (p)-[:Directed]->(m);
MATCH (p:Person {name: 'Tom Tykwer'}), (m:Movie {name: 'Cloud Atlas'})
CREATE (p)-[:Directed]->(m);
MATCH (p:Person {name: 'Lilly Wacholoy'}), (m:Movie {name: 'Cloud Atlas'})
CREATE (p)-[:Directed]->(m);
MATCH (p:Person {name: 'Lona Wacholonche'}), (m:Movie {name: 'Cloud Atlas'})
CREATE (p)-[:Directed]->(m);

MATCH (p:Person {name: 'Tom Hanks'}), (m:Movie {name: 'A League of Thier Own'})
CREATE (p)-[:ACTED_IN]->(m);
MATCH (p:Person {name: 'Tom Hanks'}), (m:Movie {name: 'The Polar Express'})
CREATE (p)-[:ACTED_IN]->(m);
MATCH (p:Person {name: 'Tom Hanks'}), (m:Movie {name: 'Cast Away'})
CREATE (p)-[:ACTED_IN]->(m);
MATCH (p:Person {name: 'Tom Hanks'}), (m:Movie {name: 'Apollo 13'})
CREATE (p)-[:ACTED_IN]->(m);
MATCH (p:Person {name: 'Tom Hanks'}), (m:Movie {name: 'That Things You Do'})
CREATE (p)-[:ACTED_IN]->(m);
MATCH (p:Person {name: 'Tom Hanks'}), (m:Movie {name: 'Cloud Atlas'})
CREATE (p)-[:ACTED_IN]->(m);
MATCH (p:Person {name: 'Tom Hanks'}), (m:Movie {name: "You've Got the Mail"})
CREATE (p)-[:ACTED_IN]->(m);
MATCH (p:Person {name: 'Tom Hanks'}), (m:Movie {name: 'Joe Verus The Valacano'})
CREATE (p)-[:ACTED_IN]->(m);








CREATE (e1:Person {name: 'DAN', age: 35, salary: 80000, address: '123 Main St', dependents: 2, gender: 'Male'}),
(e2:Person {name: 'ANN', age: 28, salary: 60000, address: '456 Oak Ave', dependents: 0, gender: 'Female'}),
(e3:Person {name: 'SALLY', age: 42, salary: 90000, address: '789 Maple Rd', dependents: 3, gender: 'Female'}),
(e4:Person {name: 'MELISSA', age: 30, salary: 75000, address: '111 Elm St', dependents: 1, gender: 'Female'}),
(e5:Person {name: 'JENIFFER', age: 27, salary: 65000, address: '222 Pine Ave', dependents: 0, gender: 'Female'}),
(e6:Person {name: 'DIANA', age: 40, salary: 95000, address: '333 Cedar Ln', dependents: 2, gender: 'Female'}),
(e7:Person {name: 'JOE', age: 45, salary: 100000, address: '444 Maple St', dependents: 1, gender: 'Male'}),
(e8:Person {name: 'JOHN', age: 32, salary: 85000, address: '555 Oak Ave', dependents: 2, gender: 'Male'}),
(e9:Person {name: 'MARK', age: 29, salary: 70000, address: '666 Elm St', dependents: 0, gender: 'Male'})
CREATE(c1:Company {name: 'XYZ', net_worth: 5000000, year_founded: 2000}),
(c2:Company {name: 'NeO4j', n   et_worth: 10000000, year_founded: 2007}),
(c3:Company {name: 'ABC', net_worth: 2000000, year_founded: 1995}),
(c4:Company {name: 'Company1', net_worth: 8000000, year_founded: 2010}),
(c5:Company {name: 'Company2', net_worth: 3000000, year_founded: 2005})
CREATE(l1:Language {name: 'INTEGRATION', developed_by: 'IBM', year_created: 2005}),
(l2:Language {name: 'APPLICATION', developed_by: 'Microsoft', year_created: 1998}),
(l3:Language {name: 'DATA_ETL', developed_by: 'Oracle', year_created
: 2001}),
(l4:Language {name: 'QUERY_LANGUAGE', developed_by: 'Google', year_created: 2009}),
(l5:Language {name: 'GRAPHS', developed_by: 'Neo4j', year_created: 2010}),
(l6:Language {name: 'JAVA', developed_by: 'Sun Microsystems', year_created: 1995})


(e8)-[:WORKS_FOR]->(c1),
(e8)-[:LIKES]->(l6),
(e8)-[:LIKES]->(l2),
(e8)-[:IS_FRIEND_WITH]->(e3),

(e1)-[:LIKES]->(l1),
(e1)-[:LIKES]->(l3),
(e1)-[:WORKS_FOR]->(c3),

(e2)-[:LIKES]->(l2),
(e2)-[:WORKS_FOR]->(c3),
(e2)-[:IS_FRIEND_WITH]->(e1),

(e3)-[:LIKES]->(l1),
(e3)-[:WORKS_FOR]->(c1),

(e4)-[:LIKES]->(l3),
(e4)-[:LIKES]->(l4),
(e4)-[:LIKES]->(l5),
(e4)-[:WORKS_FOR]->(c5),

(e5)-[:LIKES]->(l5),
(e5)-[:LIKES]->(l6),
(e5)-[:IS_FRIEND_WITH]->(e9),
(e5)-[:IS_FRIEND_WITH]->(e4),
(e5)-[:IS_FRIEND_WITH]->(e2),
(e5)-[:IS_FRIEND_WITH]->(e3),
(e5)-[:IS_FRIEND_WITH]->(e8),
(e5)-[:WORKS_FOR]->(c2),
(e6)-[:LIKES]->(l5),
(e6)-[:LIKES]->(l4),
(e6)-[:WORKS_FOR]->(c4),

(e7)-[:LIKES]->(l4),
(e7)-[:IS_FRIEND_WITH]->(e9),
(e7)-[:IS_FRIEND_WITH]->(e6),

(e9)-[:LIKES]->(l5)
