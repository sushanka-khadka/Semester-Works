document.getElementById('registrationForm').addEventListener('submit', function(e) {
    e.preventDefault()

    let valid= true;

    const showError= (id, message) => {
        document.getElementById(id).textContent= message
        valid= false
    }

    const clearError= (id)=>{
        document.getElementById(id).textContent= ''

    }

    const nameRegex= /^[a-zA-Z]{1,50}$/
    const phoneRegex= /^9[7-8][0-9]{8}$/
    const emailRegex= /^[^\s@]+@[^\s@]+\.[^\s@]+$/    
    const usernameRegex = /^[A-Za-z][A-Za-z0-9@_]{5,14}$/;
    const passwordRegex = /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[^A-Za-z0-9]).{8,20}$/;

    const fname= document.getElementById('fname').value.trim()
    const lname= document.getElementById('lname').value.trim()
    const dob= document.getElementById('dob').value
    const gender= document.getElementById('gender').value
    const province= document.getElementById('province').value
    const phone= document.getElementById('phone').value.trim()
    const email= document.getElementById('email').value.trim()
    const username= document.getElementById('username').value.trim()
    const password= document.getElementById('password').value
    const confirmPass= document.getElementById('confirmPass').value

    //first name
    if(!fname || !nameRegex.test(fname)){
        showError('fnameError', 'Required. Only alphabets upto 50 characters long.')        
    }else{
        clearError('fnameError')
    }
    
    // last name (optional)
    if(lname && !nameRegex.test(lname)){
        showError('lnameError', 'Only alphabets upto 50 characters long.')        
    }else{
        clearError('lnameError')
    }

    // dob
    if(!dob){
        showError('dobError', 'Date of Birth is required.')        
    }else{
        clearError('dobError')
    }

    // Gender
    if(!gender){
        showError('genderError', 'Gender is required.')        
    }else{
        clearError('genderError')
    }
    
    // province
    if(!province){
        showError('provinceError', 'Province is required.')        
    }else{
        clearError('provinceError')
    }

    // Phone
    if(!phoneRegex.test(phone)){
        showError('phoneError', 'Phone is required.')        
    }else{
        clearError('phoneError')
    }

    // email(optional)
    if(email && !emailRegex.test(email)){
        showError('emailError', 'Invalid Email format!')        
    }else{
        clearError('emailError')
    }

    // username
    if(!username || !usernameRegex.test(username)){
        showError('usernameError', 'Start with letter, allow digits/@/_, 6–15 chars.')        
    }else{
        clearError('usernameError')
    }

    // password
    if(!password || !passwordRegex.test(password)){
        showError('passwordError', 'Must include uppercase, lowercase, digit, special char, 8–20 chars.')                
    }else{
        clearError('passwordError')
    }

    // confirm passowrd
    if(confirmPass !== password){
        showError('confirmPassError', 'Passwords do not match.')        
    }else{
        clearError('confirmPassError')
    }

    if (valid){
        alert('Regristration Successful!')
        this.submit()  // (optional)
    }

})