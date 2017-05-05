using UnityEngine;

public class ShellExplosion : MonoBehaviour
{
    public LayerMask m_TankMask;
    public ParticleSystem m_ExplosionParticles;       
    public AudioSource m_ExplosionAudio;              
    public float m_MaxDamage = 100f;                  
    public float m_ExplosionForce = 1000f;            
    public float m_MaxLifeTime = 2f;                  
    public float m_ExplosionRadius = 5f;              


    private void Start()
    {
        Destroy(gameObject, m_MaxLifeTime);
    }


    private void OnTriggerEnter(Collider other)
    {
        // Find all the tanks in an area around the shell and damage them.

		// Get all the objects that the shell's radius can touch
		// Onl choose the layers in which the tanks exist.
		Collider[] colliders = Physics.OverlapSphere(transform.position, m_ExplosionRadius, m_TankMask);

		for (int i = 0; i < colliders.Length; i++) {
			Rigidbody targetRigidbody = colliders [i].GetComponent<Rigidbody> ();


			// Just in case we don't find a rigidbody even though we made everything over thre and are sure
			// it's going to have one
			if (!targetRigidbody)
				continue;

			targetRigidbody.AddExplosionForce (m_ExplosionForce, transform.position, m_ExplosionRadius);

			TankHealth targetHealth = targetRigidbody.GetComponent<TankHealth> ();

			if (!targetHealth)
				continue;

			float damage = CalculateDamage (targetRigidbody.position);

			targetHealth.TakeDamage (damage);
		
		}

		m_ExplosionParticles.transform.parent = null;
		m_ExplosionParticles.Play ();

		m_ExplosionAudio.Play ();

		Destroy (m_ExplosionParticles.gameObject, m_ExplosionParticles.duration);
		Destroy (gameObject);
    }


    private float CalculateDamage(Vector3 targetPosition)
    {
        // Calculate the amount of damage a target should take based on it's position.
		Vector3 explosionToTarget = targetPosition - transform.position;

		float explosionDistance = explosionToTarget.magnitude; // finding the distance

		float relativeDistance = (m_ExplosionRadius - explosionDistance) / m_ExplosionRadius;


		float damage = relativeDistance * m_MaxDamage;

		damage = Mathf.Max (0f, damage); // if negative make zero, else let it be

		return damage;
    }
}