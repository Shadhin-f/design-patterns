<?php
require 'vendor/autoload.php';

use Kreait\Firebase\Factory;

class FirebaseConfig {
    public static function getFirestore() {
        $factory = (new Factory)->withServiceAccount(__DIR__ . '/../firebase_credentials.json');
        return $factory->createFirestore()->database();
    }

    public static function getAuth() {
        $factory = (new Factory)->withServiceAccount(__DIR__ . '/../firebase_credentials.json');
        return $factory->createAuth();
    }
}
?>
