function validateFormOnSubmit(contact) {

    validateFirstName(contact.first_name);
    validateLastName(contact.last_name);
    validatePet(contact);
    
    // so stop the form from getting submitted
    return false;
}


// Validating First Name
function validateFirstName(name) {
    
    if(name.value.length == 0) {
        name.style.background = 'Red';        document.getElementById('first_name_error').innerHTML = "The required field has not been filled in";
    }
    else {
        name.style.background = 'White';
        document.getElementById('first_name_error').innerHTML = '';
    }
    
}

// validating last name, could  have used the same function for both first name and last name but I chose to use two
function validateLastName(name) {
    
    if(name.value.length == 0) {
        name.style.background = 'Red';
        document.getElementById('last_name_error').innerHTML = "The required field has not been filled in";
    }
    else {
        name.style.background = 'White';
        document.getElementById('last_name_error').innerHTML = '';
    }
}

function validatePet(contact) {
    if (contact.pet[0].checked !== false && contact.pet[1].checked !== false) {
        document.getElementById('pet_error').innerHTML = 'Please Select an Option.';        
    }
}