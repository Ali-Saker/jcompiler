
class AccessProperty{
private:
	int publicFrequency;
	int abstractFrequency;
	int finalFrequency;
	int protectedFrequency;
	int privateFrequency;
	int staticFrequency;
	int transientFrequency;
	int volatileFrequency;
	int nativeFrequency;
	int synchronizedFrequency;
	void checkRepeatedModifiers(int, int, char *);
	void checkConflictedModifiers(int, int, char *);
	
public:
	AccessProperty();
	void setAccessProperty(int);
	bool isPublic();
	bool isAbstract();
	bool isFinal();
	bool isProtected();
	bool isPrivate();
	bool isStatic();
	bool isTransient();
	bool isVolatile();
	bool isNative();
	bool isSynchronized();
	void validAsClassAccessProperty(int, int, char *);
	void validAsInnerClassAccessProperty(int, int, char *);
	void validAsInterfaceAccessProperty(int, int, char *);
	void validAsInterfaceFieldAccessProperty(int, int, char *);
	void validAsInterfaceMethodAccessProperty(int, int, char *);
	void validAsMethodAccessProperty(int, int, char *);
	void validAsFieldAccessProperty(int, int, char *);
	void validAsLocalVariableAccessProperty(int, int, char*);
};