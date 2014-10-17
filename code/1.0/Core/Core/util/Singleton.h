//
//  Singleton.h
//  Core
//
//  Created by 孙昕 on 14-10-13.
//
//

#ifndef __Core__Singleton__
#define __Core__Singleton__

template<class T>
class CoreSingleton
{
private:
    CoreSingleton();
    CoreSingleton(const CoreSingleton&);
    ~CoreSingleton();
    CoreSingleton &operator=(const CoreSingleton&);
protected:
    static T* m_pObj;
    static bool m_bInit;
public:
    static void SetInstance(T *pObj)
    {
        m_bInit=1;
        m_pObj=pObj;
    }
    static T *GetInstance()
    {
        if(!m_bInit)
        {
            m_pObj=0;
        }
        return m_pObj;
    }
    static void Release()
    {
        m_bInit=0;
    }
};
template<class T>
bool CoreSingleton<T>::m_bInit=0;

template<class T>
T* CoreSingleton<T>::m_pObj=0;


#endif /* defined(__Core__Singleton__) */








