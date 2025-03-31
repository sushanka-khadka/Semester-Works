class Job:
    def __init__(self, company, position, salary, location):
        self.company = company
        self.position = position
        self.salary = salary
        self.location = location

    def __str__(self):
        return (f"Company: {self.company}, Position: {self.position}, "
                f"Salary: {self.salary}, Location: {self.location}")

class Person:
    def __init__(self, name, location, birthdate, height, weight, job):
        self.name = name
        self.location = location
        self.birthdate = birthdate
        self.height = height
        self.weight = weight
        self.job = job

    def __str__(self):
        return (f"Name: {self.name}, Location: {self.location}, Birthdate: {self.birthdate}, "
                f"Height: {self.height}, Weight: {self.weight}, Job: [{self.job}]")

# Creating the Job object
ram_job = Job(company="ABC company", position="AI Researcher", salary="1.5 lakhs per month", location="Kathmandu")

# Creating the Person object
ram = Person(name="Ram", location="Nepal", birthdate="15th December 1990", height="6 inches", weight="75 kg", job=ram_job)

# Printing the details
print(ram)
