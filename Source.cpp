const axios = require('axios');

// Using Async/Await
async function registerNewUser(userData) {
    try {
        const response = await axios.post('your_api_endpoint/register', userData);
        return response.data;
    }
    catch (error) {
        console.error('Error registering new user:', error.message);
        throw error;
    }
}

// Or using Promises
function registerNewUserPromise(userData) {
    return axios.post('your_api_endpoint/register', userData)
        .then(response = > response.data)
        .catch (error = > {
        console.error('Error registering new user:', error.message);
        throw error;
    });
}

// Example usage:
// Assuming you have an async function to run this code
async function run() {
    const newUser = {
      username: 'new_user',
      password : 'password123',
      // Add other user details as needed
    };

    try {
        const registeredUser = await registerNewUser(newUser);
        console.log('Registered User:', registeredUser);
    }
    catch (error) {
        // Handle errors if needed
    }
}

// Or for the Promise version
const newUser = {
  username: 'new_user',
  password : 'password123',
  // Add other user details as needed
};

registerNewUserPromise(newUser)
.then(registeredUser = > console.log('Registered User:', registeredUser))
.catch (error = > {
    // Handle errors if needed
});
