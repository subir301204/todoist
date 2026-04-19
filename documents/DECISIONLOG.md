# This is the DEecision Log for ths project
Here I will document why I took each decision

---

## V1
### Decisions
- Creation of a Makefile
- Creation of a test script
- Add install command in the Make file
- Update the exe file name to 'todo'
- Create the utility userdefine header
- Create the usage function

### Why this decision?
- **Why I have created a Makefile?**
  - I have created the Makefile to automate the building and testing process of the tool in the development process.
- **Why I have created a seperated test script?**
  - I have created the test script for scalability.
  - I will scale the tool very large, so I need to test it on that stage.
  - So I make the test cases in a test script where I can add or edit them as much I want.
- **Why I have added a install command in the Makefile?**
  - The install command will first build the exe file and then it will copy it to a spacific place to the C drive, So I can use the tool globally.
  - This is the main reason why I have added the install command to the Makefile.
  - For a updated exe file, you have to just re-run the install command.
- **Why I have updated the exe file name to 'todo'?**
  - As I have added the install command to the Makefile, So I can use it globally.
  - So I have make a little easyer to use it by shorting it's name to 'todo'.
- **Why I have created the userdefine header file?**
  - I have created the utility header to create and maintain the userdefine functions to help in general task in the project.
- **Why I have created the usage function?**
  - I have created the usage function to display the usage syntax of the tool to the user.
