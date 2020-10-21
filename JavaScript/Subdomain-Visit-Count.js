/**
* Subdomain Visit Count
* Easy
* @param {string[]} cpdomains
* @return {string[]}

Example 1:

Given arr = ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"].

call subdomainVisits(arr) -> ["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]

Explanation: We will visit "google.mail.com" 900 times, "yahoo.com" 50 times, "intel.mail.com" once and "wiki.org" 5 times. For the subdomains, we will visit "mail.com" 900 + 1 = 901 times, "com" 900 + 50 + 1 = 951 times, and "org" 5 times.

* Logic : Use built in methods split() and substring() to split domains
          and remove the counted subdomain every iteration with substring()
* Runtime: 92 ms faster than 84.31% 
* Memory Usage: 41.2 MB less than 70.87%
*
*/

var subdomainVisits = function (cpdomains) {
  if (!cpdomains || cpdomains.length <= 0) return [];
  let map = new Map();
  for (let dom of cpdomains) {
    let [num, name] = dom.split(" ");
    while (name.indexOf(".") >= 0) {
      map.set(name, map.get(name) + Number(num) || Number(num));
      name = name.substring(name.indexOf(".") + 1);
    }
    map.set(name, map.get(name) + Number(num) || Number(num));
  }
  let res = [];
  for (let [key, value] of map.entries()) {
    res.push(`${value} ${key}`);
  }
  return res;
};
