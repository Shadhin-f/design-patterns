// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getAnalytics } from "firebase/analytics";
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
// For Firebase JS SDK v7.20.0 and later, measurementId is optional
const firebaseConfig = {
  apiKey: "AIzaSyBjEI7uWCBb1mZac6sfGEMYinowAHmriUQ",
  authDomain: "tour-package-db.firebaseapp.com",
  projectId: "tour-package-db",
  storageBucket: "tour-package-db.firebasestorage.app",
  messagingSenderId: "860518367174",
  appId: "1:860518367174:web:b9507e65d2f2a065f83cc7",
  measurementId: "G-64YXD58K54"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
const analytics = getAnalytics(app);