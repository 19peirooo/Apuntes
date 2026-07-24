# 6. Firebase Auth

Status: Not started
🪴 Units: 7. Base datos (../Unidades/7%20Base%20datos%20343eeadeed7082648c4f817840eb78e6.md)

Firebase Authentication nos permite gestionar usuarios de forma sencilla y segura. Vamos a ver cómo implementar el registro y el login en nuestra app de Android con Kotlin.

## Configuración inicial

Primero, necesitamos añadir las dependencias en nuestro `build.gradle`:

```kotlin
dependencies {
    implementation(platform("com.google.firebase:firebase-bom:32.7.0"))
    implementation("com.google.firebase:firebase-auth-ktx")
}
```

## Registro con Email y Contraseña

Para registrar un nuevo usuario, utilizamos el método `createUserWithEmailAndPassword`:

```kotlin
val auth = Firebase.auth

fun registrarUsuario(email: String, password: String) {
    auth.createUserWithEmailAndPassword(email, password)
        .addOnCompleteListener { task ->
            if (task.isSuccessful) {
                // Usuario registrado correctamente
                val user = auth.currentUser
                Log.d("Auth", "Usuario creado: ${user?.uid}")
            } else {
                // Error en el registro
                Log.e("Auth", "Error: ${task.exception?.message}")
            }
        }
}
```

## Iniciar Sesión

Para que un usuario existente inicie sesión:

```kotlin
fun iniciarSesion(email: String, password: String) {
    auth.signInWithEmailAndPassword(email, password)
        .addOnCompleteListener { task ->
            if (task.isSuccessful) {
                // Login exitoso
                val user = auth.currentUser
                Toast.makeText(context, "Bienvenido ${user?.email}", Toast.LENGTH_SHORT).show()
            } else {
                // Error en el login
                Toast.makeText(context, "Credenciales incorrectas", Toast.LENGTH_SHORT).show()
            }
        }
}
```

## 

## Puntos importantes

- Siempre valida los campos antes de enviarlos a Firebase (email válido, contraseña de al menos 6 caracteres)
- Maneja los errores de forma apropiada y muestra mensajes claros al usuario
- Utiliza `addOnCompleteListener` para operaciones asíncronas
- Considera implementar `AuthStateListener` para escuchar cambios en el estado de autenticación
- No olvides configurar las reglas de seguridad en la consola de Firebase