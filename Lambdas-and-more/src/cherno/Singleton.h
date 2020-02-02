#pragma once

namespace Cherno
{
	class Singleton
	{
	public:

		/// Return a local static reference so you do not have to have an instance as a member
		static Singleton& getInstance();
		bool itsOver9000() const;
		void powerUp();
		int getPowerLevel() const;

	private:
		Singleton() = default;
		~Singleton() = default;

	public:
		Singleton(const Singleton& other) = delete;
		Singleton(Singleton&& other) noexcept = delete;
		Singleton& operator=(const Singleton& other) = delete;
		Singleton& operator=(Singleton&& other) noexcept = delete;
	private:
		int powerLevel = 9000;
	};
}
