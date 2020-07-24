## Pull Request Process

1. Ensure any install or build dependencies are removed before the end of the layer when doing a 
   build.
2. Update the README.md with details of changes to the interface, this includes new environment 
   variables, exposed ports, useful file locations and container parameters.
3. You may merge the Pull Request in once you have the sign-off of two other developers, or if you 
   do not have permission to do that, you may request the second reviewer to merge it for you.
   
## How to Contribute

- Fork this repository - [How to fork a repository](https://services.github.com/on-demand/intro-to-github/create-pull-request)
- Clone the forked repository into local space
- Choose any problem on [LeetCode](https://www.leetcode.com/) (or choose your already solved question)
- Paste the solution code in new file and name it in following format:
PROBLEM_NAME.[Format of language used in your code]
(you should match it with the url, such that when a user type the url 
leetcode.com/problems/PROBLEM_NAME/
and so on
it will be redirected to the actual problem page)
- Place your source code file in respective folder (Java/Python/JS/C++)
- Optional - You can add comments at the start of the file, if you want to share something, like steps to run the code etc
- Add and commit the changes. (Please do not make changes in any other file, but if you want to work on bug/improvement then add an issue first)
- Don't forget to add your name, image url, country and the language used in contributors table in the README.md file
- Generate a Pull Request (Optional: add problem name in the title and url to the problem in description). Confused how to create a pull request ? <br> [Check here](https://www.digitalocean.com/community/tutorials/how-to-create-a-pull-request-on-github#create-pull-request)
- That's it, you have successfully completed your first PR contribution. Well Done!!!


## How to Sync Forked Repo from Upstream Repo

1. Add the original repository as an upstream repository

```javascript
$ git remote add upstream https://github.com/[Original Owner Username]/[Original Repository].git
```
Hence, in this repository it would be

```javascript
$ git remote add upstream https://github.com/codedecks-in/LeetCode-Solutions.git/
```

2. Fetch all the changes from the repository. Note that commits to the original repository will be stored in a local branch called, upstream/master

```javascript
$ git fetch upstream
```

3. Make sure that you are on your fork's master or working branch

```javascript
$ git checkout [working branch]
```

For example,
```javascript
$ git checkout master
```

4. Merge the changes from the upstream/master into  your local master or working branch. This will sync the fork's master branch with the upstream repository without losing your local changes. If you have made any changes that create conflict, you will have to resolve the conflict before you can complete the merge

```javascript
$ git merge upstream/master
```

5. At this point, your local branch is synced with the upstream/master branch. In order to update the remote branch in Github, you need to push your changes
```javascript
$ git push origin master
```
