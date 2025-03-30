class MedicalExpertSystem:
    def __init__(self):
        self.diseases = {
            "Common Cold": ["cough", "sneezing", "runny nose", "sore throat"],
            "Flu": ["fever", "chills", "muscle aches", "cough", "congestion"],
            "COVID-19": ["fever", "dry cough", "tiredness", "loss of taste or smell"],
            "Allergy": ["sneezing", "itchy eyes", "runny nose", "rash"],
            "Pneumonia": ["fever", "chills", "cough", "shortness of breath"]
        }

    def diagnose(self, symptoms):
        possible_diseases = []
        for disease, disease_symptoms in self.diseases.items():
            matching_symptoms = set(symptoms).intersection(set(disease_symptoms))
            if matching_symptoms:
                possible_diseases.append((disease, len(matching_symptoms)))

        # Sort possible diseases by the number of matching symptoms, descending
        possible_diseases.sort(key=lambda x: x[1], reverse=True)

        # Return only the disease names in the sorted order
        return [disease for disease, _ in possible_diseases]


if __name__ == "__main__":
    expert_system = MedicalExpertSystem()

    # Test with symptoms that should trigger a match
    symptoms = ["fever", "cough", "tiredness"]  # Example symptoms

    diagnosis = expert_system.diagnose(symptoms)
    if diagnosis:
        print("Possible diseases based on symptoms:", diagnosis)
    else:
        print("No matching diseases found.")
