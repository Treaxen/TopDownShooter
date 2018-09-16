#ifndef  _OBJECTPOOL_H
#define _OBJECTPOOL_H

#include <list>
#include <iostream>

namespace objectpool
{
	template<class TYPE>
	class ObjectPool
	{
	private:
		std::list<TYPE*> m_objectList;

	public:

		//! Returns an object from the pull, creates a new object if the pool is used up or empty
		TYPE * getObject()
		{
			if (m_objectList.empty())
			{
				return new TYPE();
			}
			else
			{
				TYPE* type = m_objectList.front();
				m_objectList.pop_front();
				return type;
			}
		}

		void returnObject(TYPE* type)
		{
			m_objectList.push_back(type);
		}
	};
}

#endif // ! _OBJECTPOOL_H


#pragma once
